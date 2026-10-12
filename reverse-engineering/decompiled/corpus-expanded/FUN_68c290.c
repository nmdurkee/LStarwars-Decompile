/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68c290; label: FUN_0068c290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0068c290(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  if ((&DAT_02924b60)[param_1 * 0x16] != -1) {
    iVar7 = (&DAT_02924b60)[param_1 * 0x16] * 0x330;
    *(undefined4 *)(iVar7 + 400 + DAT_029620a4) = *param_2;
    *(undefined4 *)(iVar7 + 0x194 + DAT_029620a4) = uVar1;
    *(undefined4 *)(iVar7 + 0x198 + DAT_029620a4) = uVar2;
    *(undefined4 *)(iVar7 + 0x300 + DAT_029620a4) = 0;
  }
  FUN_00684640((&DAT_02924b60)[param_1 * 0x16],(undefined2)DAT_02962ab4,(undefined2)DAT_02962ab8);
  FUN_006846a0((&DAT_02924b60)[param_1 * 0x16],(undefined2)DAT_02962aa8,(undefined2)DAT_02962aac,
               (undefined2)DAT_02962ab0);
  FUN_00655ba0((&DAT_02924b60)[param_1 * 0x16],(undefined2)DAT_02962ac0,(undefined2)DAT_02962ac4,
               (&DAT_02924b94)[param_1 * 0x16],(&DAT_02924b98)[param_1 * 0x16]);
  uVar4 = (undefined2)DAT_02962ad4;
  cVar3 = (&DAT_02924ba3)[param_1 * 0x58];
  if (cVar3 != '\0') {
    (&DAT_02924ba4)[param_1 * 0x2c] = (undefined2)DAT_02962ad0;
    (&DAT_02924ba6)[param_1 * 0x2c] = uVar4;
    FUN_00684720((&DAT_02924b60)[param_1 * 0x16],cVar3,(&DAT_02924ba4)[param_1 * 0x2c],uVar4);
  }
  (&DAT_02924b50)[param_1 * 0x16] = *param_2;
  uVar4 = (undefined2)DAT_02962aa8;
  (&DAT_02924b54)[param_1 * 0x16] = param_2[1];
  uVar5 = (undefined2)DAT_02962aac;
  (&DAT_02924b58)[param_1 * 0x16] = param_2[2];
  uVar6 = (undefined2)DAT_02962ab0;
  (&DAT_02924b68)[param_1 * 0x2c] = uVar4;
  uVar4 = (undefined2)DAT_02962ab4;
  (&DAT_02924b6c)[param_1 * 0x2c] = uVar6;
  uVar6 = (undefined2)DAT_02962ac0;
  (&DAT_02924b6a)[param_1 * 0x2c] = uVar5;
  uVar5 = (undefined2)DAT_02962ab8;
  (&DAT_02924b64)[param_1 * 0x2c] = uVar4;
  uVar4 = (undefined2)DAT_02962ac4;
  (&DAT_02924b90)[param_1 * 0x2c] = uVar6;
  (&DAT_02924b66)[param_1 * 0x2c] = uVar5;
  (&DAT_02924b92)[param_1 * 0x2c] = uVar4;
  return param_1;
}

