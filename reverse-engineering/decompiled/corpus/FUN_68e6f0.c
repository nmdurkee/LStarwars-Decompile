/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68e6f0; label: FUN_0068e6f0
 */

void FUN_0068e6f0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x58;
  piVar1 = &DAT_02924b60 + param_1 * 0x16;
  if ((&DAT_02924b60)[param_1 * 0x16] == -1) {
    FUN_00684ee0(piVar1,(&DAT_02924b5c)[param_1 * 0x16],(&DAT_02924b50)[param_1 * 0x16],
                 (&DAT_02924b54)[param_1 * 0x16],(&DAT_02924b58)[param_1 * 0x16]);
    if (*piVar1 != -1) {
      *(undefined1 *)(*piVar1 * 0x330 + 0x2f9 + DAT_029620a4) = 0;
      FUN_00684640(*piVar1,(&DAT_02924b64)[param_1 * 0x2c],(&DAT_02924b66)[param_1 * 0x2c]);
      FUN_006846a0(*piVar1,(&DAT_02924b68)[param_1 * 0x2c],(&DAT_02924b6a)[param_1 * 0x2c],
                   (&DAT_02924b6c)[param_1 * 0x2c]);
      FUN_00655c30(*piVar1 * 0x330 + DAT_029620a4,(&DAT_02924b70)[param_1 * 0x16]);
      FUN_00655dd0(*piVar1,(&DAT_02924b84)[param_1 * 0x16],(&DAT_02924b88)[param_1 * 0x16],
                   (&DAT_02924b8c)[param_1 * 0x16]);
      FUN_00655ba0(*piVar1,(&DAT_02924b90)[param_1 * 0x2c],(&DAT_02924b92)[param_1 * 0x2c],
                   (&DAT_02924b94)[param_1 * 0x16],(&DAT_02924b98)[param_1 * 0x16]);
      FUN_00684720(*piVar1,(&DAT_02924ba3)[iVar2],(&DAT_02924ba4)[param_1 * 0x2c],
                   (&DAT_02924ba6)[param_1 * 0x2c]);
      if (*piVar1 != -1) {
        *(undefined2 *)(*piVar1 * 0x330 + 0x2f0 + DAT_029620a4) = (&DAT_02924b9c)[param_1 * 0x2c];
      }
      FUN_00655f30(*piVar1,*(undefined4 *)(&DAT_02947bdc + (char)(&DAT_02924ba1)[iVar2] * 4));
      *(undefined1 *)(*piVar1 * 0x330 + 0x1da + DAT_029620a4) = (&DAT_02924ba2)[iVar2];
    }
  }
  return;
}

