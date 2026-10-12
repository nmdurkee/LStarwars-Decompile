/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68d2c0; label: FUN_0068d2c0
 */

void FUN_0068d2c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02920ab8 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_006630f0,"Particle Life");
    if (DAT_02920ab8 != 0) {
      uVar2 = FUN_00625150(0,&local_10,0,&LAB_0068d270,0,0x41200000,*(undefined4 *)(iVar1 + 0xa4),
                           "Particle Life");
      FUN_00618e10(DAT_02920ab8,uVar2);
      FUN_006279b0(param_1,DAT_02920ab8);
      *(int *)(DAT_02920ab8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920ab8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

