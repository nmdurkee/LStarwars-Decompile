/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571890; label: FUN_00571890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00571890(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                  undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(*param_1 + 0xfU & 0xfffffff0);
  *param_1 = (*param_1 + 0xfU & 0xfffffff0) + 0xc;
  if (piVar4 != (int *)0x0) {
    piVar4[2] = 0;
    *piVar4 = param_4;
    piVar4[1] = param_3;
    piVar4[2] = *param_1 + 0xfU & 0xfffffff0;
    *param_1 = (*param_1 + 0xfU & 0xfffffff0) + param_3 * 0x14;
    if ((void *)piVar4[2] != (void *)0x0) {
      _memset((void *)piVar4[2],-1,param_3 * 0x14);
      iVar5 = 0;
      if ((param_5 != 0) && (0 < *piVar4)) {
        iVar2 = 0;
        do {
          FUN_004f1f10(piVar4[2] + 4 + iVar2,*(undefined4 *)(param_5 + iVar5 * 4));
          *(undefined4 *)(iVar2 + piVar4[2]) = 0xffffffff;
          uVar1 = FUN_0064b020(piVar4[2] + 4 + iVar2,param_6);
          *(undefined4 *)(iVar2 + piVar4[2]) = uVar1;
          iVar5 = iVar5 + 1;
          iVar2 = iVar2 + 0x14;
        } while (iVar5 < *piVar4);
      }
      if (iVar5 < piVar4[1]) {
        iVar2 = iVar5 * 0x14;
        puVar3 = &DAT_02913a58;
        do {
          if (0x291f657 < (int)puVar3) break;
          *(undefined4 *)(iVar2 + piVar4[2]) = 0xffffffff;
          if ('\0' < (char)puVar3[0xb0]) {
            FUN_004f1f10(piVar4[2] + 4 + iVar2,puVar3);
            uVar1 = FUN_0064b020(piVar4[2] + 4 + iVar2,param_6);
            *(undefined4 *)(iVar2 + piVar4[2]) = uVar1;
            iVar5 = iVar5 + 1;
            iVar2 = iVar2 + 0x14;
          }
          puVar3 = puVar3 + 0x178;
        } while (iVar5 < piVar4[1]);
        if (iVar5 < piVar4[1]) {
          iVar2 = iVar5 * 0x14;
          do {
            *(undefined4 *)(iVar2 + piVar4[2]) = 0xffffffff;
            iVar5 = iVar5 + 1;
            iVar2 = iVar2 + 0x14;
          } while (iVar5 < piVar4[1]);
        }
      }
      return piVar4;
    }
  }
  return (int *)0x0;
}

