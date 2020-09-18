#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4973&page=2
 * 原题为同目录下的 Newbie_calculations.exe IDA输出文件为 Newbie_calculations.idb
 */

constexpr int* Add(int* a1, const int a2)
{
    *a1 += a2;
    return a1;
}

constexpr int* Sub(int* a1, const int a2)
{
    *a1 -= a2;
    return a1;
}

constexpr int* Mul(int* a1, const int a2)
{
    *a1 *= a2;
    return a1;
}

int main()
{
    int flag[32];
    memset(flag, 1, sizeof(flag));
	
    auto v3 = Mul(flag, 1000000000);
    auto v4 = Sub(v3, 999999950);
    Mul(v4, 2);
    auto v5 = Add(&flag[1], 5000000);
    auto v6 = Sub(v5, 6666666);
    auto v7 = Add(v6, 1666666);
    auto v8 = Add(v7, 45);
    auto v9 = Mul(v8, 2);
    Add(v9, 5);
    auto v10 = Mul(&flag[2], 1000000000);
    auto v11 = Sub(v10, 999999950);
    auto v12 = Mul(v11, 2);
    Add(v12, 2);
    auto v13 = Add(&flag[3], 55);
    auto v14 = Sub(v13, 3);
    auto v15 = Add(v14, 4);
    Sub(v15, 1);
    auto v16 = Mul(&flag[4], 100000000);
    auto v17 = Sub(v16, 99999950);
    auto v18 = Mul(v17, 2);
    Add(v18, 2);
    auto v19 = Sub(&flag[5], 1);
    auto v20 = Mul(v19, 1000000000);
    auto v21 = Add(v20, 55);
    Sub(v21, 3);
    auto v22 = Mul(&flag[6], 1000000);
    auto v23 = Sub(v22, 999975);
    Mul(v23, 4);
    auto v24 = Add(&flag[7], 55);
    auto v25 = Sub(v24, 33);
    auto v26 = Add(v25, 44);
    Sub(v26, 11);
    auto v27 = Mul(&flag[8], 10);
    auto v28 = Sub(v27, 5);
    auto v29 = Mul(v28, 8);
    Add(v29, 9);
    auto v30 = Add(&flag[9], 0);
    auto v31 = Sub(v30, 0);
    auto v32 = Add(v31, 11);
    auto v33 = Sub(v32, 11);
    Add(v33, 53);
    auto v34 = Add(&flag[10], 49);
    auto v35 = Sub(v34, 2);
    auto v36 = Add(v35, 4);
    Sub(v36, 2);
    auto v37 = Mul(&flag[11], 1000000);
    auto v38 = Sub(v37, 999999);
    auto v39 = Mul(v38, 4);
    Add(v39, 50);
    auto v40 = Add(&flag[12], 1);
    auto v41 = Add(v40, 1);
    auto v42 = Add(v41, 1);
    auto v43 = Add(v42, 1);
    auto v44 = Add(v43, 1);
    auto v45 = Add(v44, 1);
    auto v46 = Add(v45, 10);
    Add(v46, 32);
    auto v47 = Mul(&flag[13], 10);
    auto v48 = Sub(v47, 5);
    auto v49 = Mul(v48, 8);
    auto v50 = Add(v49, 9);
    Add(v50, 48);
    auto v51 = Sub(&flag[14], 1);
    auto v52 = Mul(v51, -294967296);
    auto v53 = Add(v52, 55);
    Sub(v53, 3);
    auto v54 = Add(&flag[15], 1);
    auto v55 = Add(v54, 2);
    auto v56 = Add(v55, 3);
    auto v57 = Add(v56, 4);
    auto v58 = Add(v57, 5);
    auto v59 = Add(v58, 6);
    auto v60 = Add(v59, 7);
    Add(v60, 20);
    auto v61 = Mul(&flag[16], 10);
    auto v62 = Sub(v61, 5);
    auto v63 = Mul(v62, 8);
    auto v64 = Add(v63, 9);
    Add(v64, 48);
    auto v65 = Add(&flag[17], 7);
    auto v66 = Add(v65, 6);
    auto v67 = Add(v66, 5);
    auto v68 = Add(v67, 4);
    auto v69 = Add(v68, 3);
    auto v70 = Add(v69, 2);
    auto v71 = Add(v70, 1);
    Add(v71, 20);
    auto v72 = Add(&flag[18], 7);
    auto v73 = Add(v72, 2);
    auto v74 = Add(v73, 4);
    auto v75 = Add(v74, 3);
    auto v76 = Add(v75, 6);
    auto v77 = Add(v76, 5);
    auto v78 = Add(v77, 1);
    Add(v78, 20);
    auto v79 = Mul(&flag[19], 1000000);
    auto v80 = Sub(v79, 999999);
    auto v81 = Mul(v80, 4);
    auto v82 = Add(v81, 50);
    Sub(v82, 1);
    auto v83 = Sub(&flag[20], 1);
    auto v84 = Mul(v83, -294967296);
    auto v85 = Add(v84, 49);
    Sub(v85, 1);
    auto v86 = Sub(&flag[21], 1);
    auto v87 = Mul(v86, 1000000000);
    auto v88 = Add(v87, 54);
    auto v89 = Sub(v88, 1);
    auto v90 = Add(v89, 1000000000);
    Sub(v90, 1000000000);
    auto v91 = Add(&flag[22], 49);
    auto v92 = Sub(v91, 1);
    auto v93 = Add(v92, 2);
    Sub(v93, 1);
    auto v94 = Mul(&flag[23], 10);
    auto v95 = Sub(v94, 5);
    auto v96 = Mul(v95, 8);
    auto v97 = Add(v96, 9);
    Add(v97, 48);
    auto v98 = Add(&flag[24], 1);
    auto v99 = Add(v98, 3);
    auto v100 = Add(v99, 3);
    auto v101 = Add(v100, 3);
    auto v102 = Add(v101, 6);
    auto v103 = Add(v102, 6);
    auto v104 = Add(v103, 6);
    Add(v104, 20);
    auto v105 = Add(&flag[25], 55);
    auto v106 = Sub(v105, 33);
    auto v107 = Add(v106, 44);
    auto v108 = Sub(v107, 11);
    Add(v108, 42);
    Add(&flag[26], flag[25]);
    Add(&flag[27], flag[12]);
    auto v109 = flag[27];
    auto v110 = Sub(&flag[28], 1);
    auto v111 = Add(v110, v109);
    Sub(v111, 1);
    auto v112 = flag[23];
    auto v113 = Sub(&flag[29], 1);
    auto v114 = Mul(v113, 1000000);
    Add(v114, v112);
    auto v115 = flag[27];
    auto v116 = Add(&flag[30], 1);
    Mul(v116, v115);
    Add(&flag[31], flag[30]);

    printf("CTF{");
	for (auto i : flag)
	{
        printf("%c", i);
	}
    printf("}\n");
}
