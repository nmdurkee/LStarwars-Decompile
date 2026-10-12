/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b1890; label: FUN_006b1890
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006b1890(int param_1,undefined4 *param_2,float param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  
  iVar2 = (int)param_3;
  iVar1 = (param_5 + (int)param_3) * -4;
  puVar8 = (undefined4 *)(&stack0xffffffe4 + iVar1);
  puVar9 = (undefined4 *)(&stack0xffffffe4 + iVar1);
  if (param_2 == (undefined4 *)0x0) {
    if (0 < (int)param_3) {
      for (; param_3 != 0.0; param_3 = (float)((int)param_3 + -1)) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
    }
  }
  else if (0 < (int)param_3) {
    for (; param_3 != 0.0; param_3 = (float)((int)param_3 + -1)) {
      *puVar9 = *param_2;
      param_2 = param_2 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  param_2 = (undefined4 *)0x0;
  if (0 < param_5) {
    pfVar4 = (float *)(&stack0xffffffec + iVar1);
    do {
      iVar7 = 0;
      param_3 = 0.0;
      iVar10 = (int)param_2;
      iVar11 = iVar2;
      if (3 < iVar2) {
        iVar3 = (iVar2 - 4U >> 2) + 1;
        iVar7 = iVar3 * 4;
        iVar10 = (int)param_2 + iVar7;
        iVar11 = iVar2 + iVar3 * -4;
        pfVar5 = pfVar4;
        pfVar6 = (float *)(param_1 + -8 + iVar2 * 4);
        do {
          iVar3 = iVar3 + -1;
          param_3 = (((param_3 - pfVar6[1] * pfVar5[-2]) - pfVar5[-1] * *pfVar6) -
                    pfVar6[-1] * *pfVar5) - pfVar6[-2] * pfVar5[1];
          pfVar5 = pfVar5 + 4;
          pfVar6 = pfVar6 + -4;
        } while (iVar3 != 0);
      }
      if (iVar7 < iVar2) {
        pfVar5 = (float *)(param_1 + iVar11 * 4);
        iVar7 = iVar2 - iVar7;
        do {
          iVar11 = iVar10 * 4;
          pfVar5 = pfVar5 + -1;
          iVar10 = iVar10 + 1;
          iVar7 = iVar7 + -1;
          param_3 = param_3 - *(float *)(&stack0xffffffe4 + iVar11 + iVar1) * *pfVar5;
        } while (iVar7 != 0);
      }
      *(float *)(&stack0xffffffe4 + iVar10 * 4 + iVar1) = param_3;
      *(float *)(param_4 + (int)param_2 * 4) = param_3;
      param_2 = (undefined4 *)((int)param_2 + 1);
      pfVar4 = pfVar4 + 1;
    } while ((int)param_2 < param_5);
  }
  return;
}

