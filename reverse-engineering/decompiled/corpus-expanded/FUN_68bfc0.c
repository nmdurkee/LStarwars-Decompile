/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68bfc0; label: FUN_0068bfc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0068bfc0(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int local_4;
  
  iVar6 = 0;
  local_4 = 0;
  if (DAT_02962a2c == 0x200) {
    return -1;
  }
  if (DAT_02924b60 != -1) {
    piVar3 = &DAT_02924b60;
    do {
      piVar3 = piVar3 + 0x16;
      iVar6 = iVar6 + 1;
      local_4 = iVar6;
    } while (*piVar3 != -1);
  }
  iVar6 = local_4 * 0x58;
  iVar7 = param_2 * 0x58;
  piVar3 = &DAT_02924b60 + local_4 * 0x16;
  FUN_00684ee0(piVar3,(&DAT_02924b5c)[param_2 * 0x16],*param_1,param_1[1],param_1[2]);
  if (*piVar3 == -1) {
    return -1;
  }
  *(undefined1 *)(*piVar3 * 0x330 + 0x2f9 + DAT_029620a4) = 0;
  (&DAT_02924b9c)[local_4 * 0x2c] = (&DAT_02924b9c)[param_2 * 0x2c];
  (&DAT_02924ba1)[iVar6] = (&DAT_02924ba1)[iVar7];
  (&DAT_02924b94)[local_4 * 0x16] = (&DAT_02924b94)[param_2 * 0x16];
  (&DAT_02924b98)[local_4 * 0x16] = (&DAT_02924b98)[param_2 * 0x16];
  (&DAT_02924b50)[local_4 * 0x16] = *param_1;
  (&DAT_02924b54)[local_4 * 0x16] = param_1[1];
  (&DAT_02924b58)[local_4 * 0x16] = param_1[2];
  (&DAT_02924b5c)[local_4 * 0x16] = (&DAT_02924b5c)[param_2 * 0x16];
  (&DAT_02924b64)[local_4 * 0x2c] = (&DAT_02924b64)[param_2 * 0x2c];
  (&DAT_02924b66)[local_4 * 0x2c] = (&DAT_02924b66)[param_2 * 0x2c];
  (&DAT_02924b68)[local_4 * 0x2c] = (&DAT_02924b68)[param_2 * 0x2c];
  (&DAT_02924b6a)[local_4 * 0x2c] = (&DAT_02924b6a)[param_2 * 0x2c];
  (&DAT_02924b70)[local_4 * 0x16] = (&DAT_02924b70)[param_2 * 0x16];
  (&DAT_02924b84)[local_4 * 0x16] = (&DAT_02924b84)[param_2 * 0x16];
  (&DAT_02924b88)[local_4 * 0x16] = (&DAT_02924b88)[param_2 * 0x16];
  (&DAT_02924b8c)[local_4 * 0x16] = (&DAT_02924b8c)[param_2 * 0x16];
  (&DAT_02924ba2)[iVar6] = (&DAT_02924ba2)[iVar7];
  (&DAT_02924ba3)[iVar6] = (&DAT_02924ba3)[iVar7];
  iVar7 = (&DAT_02924b5c)[local_4 * 0x16];
  (&DAT_02924ba4)[local_4 * 0x2c] = (&DAT_02924ba4)[param_2 * 0x2c];
  iVar2 = DAT_0296209c;
  (&DAT_02924ba6)[local_4 * 0x2c] = (&DAT_02924ba6)[param_2 * 0x2c];
  pcVar4 = *(char **)(iVar2 + iVar7 * 4);
  pcVar5 = &DAT_02924b74 + iVar6;
  do {
    cVar1 = *pcVar4;
    *pcVar5 = cVar1;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00684640(*piVar3,(&DAT_02924b64)[local_4 * 0x2c],(&DAT_02924b66)[local_4 * 0x2c]);
  FUN_006846a0(*piVar3,(&DAT_02924b68)[local_4 * 0x2c],(&DAT_02924b6a)[local_4 * 0x2c],
               (&DAT_02924b6c)[local_4 * 0x2c]);
  FUN_00655c30(*piVar3 * 0x330 + DAT_029620a4,(&DAT_02924b70)[local_4 * 0x16]);
  FUN_00655ba0(*piVar3,(&DAT_02924b90)[local_4 * 0x2c],(&DAT_02924b92)[local_4 * 0x2c],
               (&DAT_02924b94)[local_4 * 0x16],(&DAT_02924b98)[local_4 * 0x16]);
  FUN_00684720(*piVar3,(&DAT_02924ba3)[iVar6],(&DAT_02924ba4)[local_4 * 0x2c],
               (&DAT_02924ba6)[local_4 * 0x2c]);
  if (*piVar3 != -1) {
    *(undefined2 *)(*piVar3 * 0x330 + 0x2f0 + DAT_029620a4) = (&DAT_02924b9c)[local_4 * 0x2c];
  }
  FUN_00655f30(*piVar3,*(undefined4 *)(&DAT_02947bdc + (char)(&DAT_02924ba1)[iVar6] * 4));
  *(undefined1 *)(*piVar3 * 0x330 + 0x1da + DAT_029620a4) = (&DAT_02924ba2)[iVar6];
  DAT_02962a2c = DAT_02962a2c + 1;
  return local_4;
}

