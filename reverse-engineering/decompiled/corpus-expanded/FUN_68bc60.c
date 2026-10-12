/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68bc60; label: FUN_0068bc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0068bc60(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int local_4;
  
  iVar11 = 0;
  local_4 = 0;
  if (DAT_02962a2c == 0x200) {
    return -1;
  }
  if (DAT_02924b60 != -1) {
    piVar7 = &DAT_02924b60;
    do {
      piVar7 = piVar7 + 0x16;
      iVar11 = iVar11 + 1;
      local_4 = iVar11;
    } while (*piVar7 != -1);
  }
  iVar11 = local_4 * 0x58;
  piVar7 = &DAT_02924b60 + local_4 * 0x16;
  FUN_00684ee0(piVar7,param_2,*param_1,param_1[1],param_1[2]);
  if (*piVar7 == -1) {
    return -1;
  }
  *(undefined1 *)(*piVar7 * 0x330 + 0x2f9 + DAT_029620a4) = 0;
  (&DAT_02924b94)[local_4 * 0x16] = 0;
  (&DAT_02924b9c)[local_4 * 0x2c] = 0;
  (&DAT_02924b98)[local_4 * 0x16] = 0x3f666666;
  uVar6 = _DAT_02962abc;
  (&DAT_02924b50)[local_4 * 0x16] = *param_1;
  (&DAT_02924b54)[local_4 * 0x16] = param_1[1];
  uVar2 = (undefined2)DAT_02962ab4;
  uVar3 = param_1[2];
  (&DAT_02924b70)[local_4 * 0x16] = uVar6;
  (&DAT_02924b58)[local_4 * 0x16] = uVar3;
  (&DAT_02924b8c)[local_4 * 0x16] = 0;
  (&DAT_02924b66)[local_4 * 0x2c] = (undefined2)DAT_02962ab8;
  uVar5 = (undefined2)DAT_02962aac;
  (&DAT_02924b64)[local_4 * 0x2c] = uVar2;
  uVar2 = (undefined2)DAT_02962aa8;
  (&DAT_02924b6a)[local_4 * 0x2c] = uVar5;
  uVar4 = (undefined1)DAT_008109cc;
  (&DAT_02924b68)[local_4 * 0x2c] = uVar2;
  uVar2 = (undefined2)DAT_02962ab0;
  (&DAT_02924ba1)[iVar11] = uVar4;
  iVar8 = DAT_0296209c;
  (&DAT_02924b5c)[local_4 * 0x16] = param_2;
  (&DAT_02924b6c)[local_4 * 0x2c] = uVar2;
  (&DAT_02924b84)[local_4 * 0x16] = 0;
  (&DAT_02924b88)[local_4 * 0x16] = 0xffffffff;
  (&DAT_02924ba2)[iVar11] = 7;
  cVar1 = *(char *)(*(int *)(iVar8 + param_2 * 4) + 0x2e);
  if (cVar1 == '\x02') {
    (&DAT_02924b9e)[local_4 * 0x2c] = 40000;
  }
  else if (cVar1 == '\x03') {
    (&DAT_02924b9e)[local_4 * 0x2c] = 30000;
  }
  else if (cVar1 == '\0') {
    (&DAT_02924b9e)[local_4 * 0x2c] = 20000;
  }
  else if (cVar1 == '\a') {
    (&DAT_02924b9e)[local_4 * 0x2c] = 10000;
  }
  (&DAT_02924ba0)[iVar11] = 0;
  (&DAT_02924ba3)[iVar11] = 0;
  (&DAT_02924ba4)[local_4 * 0x2c] = 0;
  (&DAT_02924ba6)[local_4 * 0x2c] = 0;
  pcVar10 = *(char **)(iVar8 + param_2 * 4);
  pcVar9 = &DAT_02924b74 + iVar11;
  do {
    cVar1 = *pcVar10;
    *pcVar9 = cVar1;
    pcVar10 = pcVar10 + 1;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_00684640(*piVar7,(&DAT_02924b64)[local_4 * 0x2c],(&DAT_02924b66)[local_4 * 0x2c]);
  FUN_006846a0(*piVar7,(&DAT_02924b68)[local_4 * 0x2c],(&DAT_02924b6a)[local_4 * 0x2c],
               (&DAT_02924b6c)[local_4 * 0x2c]);
  FUN_00655c30(*piVar7 * 0x330 + DAT_029620a4,(&DAT_02924b70)[local_4 * 0x16]);
  FUN_00655ba0(*piVar7,(&DAT_02924b90)[local_4 * 0x2c],(&DAT_02924b92)[local_4 * 0x2c],
               (&DAT_02924b94)[local_4 * 0x16],(&DAT_02924b98)[local_4 * 0x16]);
  FUN_00684720(*piVar7,(&DAT_02924ba3)[iVar11],(&DAT_02924ba4)[local_4 * 0x2c],
               (&DAT_02924ba6)[local_4 * 0x2c]);
  if (*piVar7 != -1) {
    *(undefined2 *)(*piVar7 * 0x330 + 0x2f0 + DAT_029620a4) = (&DAT_02924b9c)[local_4 * 0x2c];
  }
  cVar1 = (&DAT_02924ba0)[iVar11];
  uVar2 = (&DAT_02924b9e)[local_4 * 0x2c];
  if (*piVar7 != -1) {
    iVar8 = *piVar7 * 0x330;
    *(char *)(iVar8 + 0x2f8 + DAT_029620a4) = cVar1;
    if (cVar1 == '\0') {
      *(undefined2 *)(iVar8 + 0x328 + DAT_029620a4) = uVar2;
    }
  }
  iVar8 = *piVar7;
  *(undefined2 *)(iVar8 * 0x330 + 0x2f2 + DAT_029620a4) = 0xffff;
  *(undefined4 *)(iVar8 * 0x330 + 0x2fc + DAT_029620a4) = 0;
  *(undefined1 *)(*piVar7 * 0x330 + 0x1da + DAT_029620a4) = (&DAT_02924ba2)[iVar11];
  iVar8 = DAT_008109cc;
  DAT_02962a2c = DAT_02962a2c + 1;
  iVar11 = *(int *)(&DAT_02947bdc + DAT_008109cc * 4);
  (&DAT_02924b10)[DAT_008109cc] = 1;
  *(undefined4 *)(&DAT_02948eb0 + iVar8 * 4) = 1;
  if (iVar11 == 0) {
    *(undefined4 *)(&DAT_02947bdc + iVar8 * 4) = DAT_02962114;
  }
  return local_4;
}

