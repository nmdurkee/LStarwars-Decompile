/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d26d0; label: FUN_005d26d0
 */

int * FUN_005d26d0(undefined4 param_1,int *param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 == (int *)0x0) {
    piVar5 = (int *)FUN_004eef40(0x400,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",
                                 0x3c2);
    param_3 = (int *)((int)piVar5 + 0x3ff);
  }
  else {
    piVar5 = (int *)(*param_2 + 3U & 0xfffffffc);
  }
  _memset(&DAT_00971b78,0,0x540);
  DAT_0096d93c = 0;
  iVar2 = FUN_004fc750(param_1);
  if (iVar2 == 0) {
    return (int *)0x0;
  }
  FUN_004f10e0(iVar2,&PTR_s_scriptmask_0080b620);
  if (param_3 <= piVar5 + 0x6f) {
    FUN_005c12e0();
  }
  FUN_005d1950(piVar5);
  DAT_00971580 = piVar5;
  iVar3 = FUN_004fc5b0(iVar2);
  while (iVar3 != 0) {
    iVar3 = FUN_004f7fb0(iVar2);
    if ((((iVar3 != 0) && (iVar4 = FUN_004fa020(iVar2), iVar4 == 0)) &&
        (pcVar1 = *(char **)(iVar2 + 0x510), *pcVar1 != '\0')) && (pcVar1[iVar3 + -1] == ':')) {
      pcVar1[iVar3 + -1] = '\0';
      iVar3 = FUN_005d1e10(*(undefined4 *)(iVar2 + 0x510));
      *(int *)(&DAT_00963e50 + iVar3 * 4) = (int)(short)DAT_00971580[0x6d];
    }
    if (param_3 <= (int *)((int)piVar5 + (short)piVar5[0x6d] * 2 + 0x1ba)) {
      FUN_005c12e0();
    }
    iVar3 = FUN_004fc5b0(iVar2);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = (int)piVar5 + (short)piVar5[0x6d] * 2 + 0x1ba;
  }
  FUN_004f12e0(iVar2);
  FUN_005d1b20(piVar5);
  *piVar5 = (int)DAT_009738d4;
  if (DAT_009738d4 != (int *)0x0) {
    *(int **)((int)DAT_009738d4 + 4) = piVar5;
  }
  piVar5[1] = 0;
  DAT_009738d4 = piVar5;
  return piVar5;
}

