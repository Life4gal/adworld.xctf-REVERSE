
from idaapi import stroffflag, offflag
import string
import random

def id_generator(size=6, chars=string.ascii_uppercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))

class bitZ(object):
    def __init__(self, ptr, size, maker):
        self.ptr = ptr
        self.size = size
        self.maker = maker


bits32 = bitZ(Dword, 4, MakeDword)
bits64 = bitZ(Qword, 8, MakeQword)

def get_bitness(addr):
    ptr = bits32
    if GetSegmentAttr(addr, SEGATTR_BITNESS) == 2:
        ptr = bits64
    return ptr

def process_segment(handler, name=".gopclntab"):
    position = 0
    for i in Segments():
        if SegName(i) == name:
            position = i
            break
    if position == 0:
        raise Exception("Couldn't find segment")
    h = handler(i, get_bitness(i))



def go_renamer(beg, ptr, make_funcs = False):
    base = beg
    pos = beg + 8 #skip header
    size = ptr.ptr(pos)
    pos += ptr.size
    end = pos + (size * ptr.size * 2)
    print "%x" % end
    while pos < end:
        offset = ptr.ptr(pos + ptr.size)
        ptr.maker(pos)         #in order to get xrefs
        ptr.maker(pos+ptr.size)
        pos += ptr.size * 2
        ptr.maker(base+offset)
        func_addr = ptr.ptr(base+offset)
        if make_funcs == True:
            MakeUnknown(func_addr, 1, DOUNK_SIMPLE)
            MakeFunction(func_addr)
        name_offset = Dword(base+offset+ptr.size)
        name = GetString(base + name_offset)
        name = name.replace('.','_').replace("<-",'_chan_left_').replace('*','_ptr_').replace('-','_').replace(';','').replace('"','').replace('\\','')
        name = name.replace('(','').replace(')','').replace('/','_').replace(' ','_').replace(',','comma').replace('{','').replace('}','')
        res = MakeNameEx(func_addr, name, idc.SN_NOWARN)
        if res == 0:
            print name
            name = name+"_autogen_"+id_generator()
            res = MakeNameEx(offset, name, idc.SN_NOWARN)
            print "Renamed as %s : %d" % (name, res)


def tryLocateGopcltab():
    pos = Functions().next() # Get some valid address in .text segment
    while True:
        possible_loc = FindBinary(pos, SEARCH_DOWN, "FB FF FF FF 00 00") #header of gopclntab
        if possible_loc == BADADDR:
            break
        if check_is_gopclntab(possible_loc):
            return possible_loc
        pos = possible_loc+1
    return None

def check_is_gopclntab(addr):
    ptr = get_bitness(addr)
    first_entry = ptr.ptr(addr+8+ptr.size)
    first_entry_off = ptr.ptr(addr+8+ptr.size*2)
    addr_func = addr+first_entry_off
    func_loc = ptr.ptr(addr_func)
    if func_loc == first_entry:
        return True
    return False

def GoRename():
    process_segment(go_renamer)


def GoRenameSectionless(val=False):
    addr = tryLocateGopcltab()
    if addr is not None:
        print "Possible Gopclnab found at: %x" % addr
        go_renamer(addr, get_bitness(addr), val)
    else:
        print "Coulnd't find gopclntab. Is this a Go binary?"

