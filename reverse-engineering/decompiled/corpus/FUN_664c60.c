/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x664c60; label: FUN_00664c60
 */

void FUN_00664c60(int param_1)

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
    DAT_02961f78 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,&LAB_00664c30,"Particle Jibber");
    if (DAT_02961f78 != 0) {
      uVar2 = FUN_00625150(0,&local_10,0,&LAB_00663110,0,0x42000000,*(undefined4 *)(iVar1 + 0xb0),
                           "Jibber X Freq");
      FUN_00618e10(DAT_02961f78,uVar2);
      DAT_02962b00 = DAT_02900c84;
      uVar2 = FUN_00625150(0,&local_10,0,&LAB_00663110,0,0x447a0000,*(undefined4 *)(iVar1 + 0xb4),
                           "Jibber X Amp");
      FUN_00618e10(DAT_02961f78,uVar2);
      DAT_02962b04 = DAT_02900c84;
      uVar2 = FUN_00625150(0,&local_10,0,&LAB_00663110,0,0x42000000,*(undefined4 *)(iVar1 + 0xb8),
                           "Jibber Y Freq");
      FUN_00618e10(DAT_02961f78,uVar2);
      DAT_02962b08 = DAT_02900c84;
      uVar2 = FUN_00625150(0,&local_10,0,&LAB_00663110,0,0x447a0000,*(undefined4 *)(iVar1 + 0xbc),
                           "Jibber Y Amp");
      FUN_00618e10(DAT_02961f78,uVar2);
      DAT_02962b0c = DAT_02900c84;
      FUN_006279b0(param_1,DAT_02961f78);
      *(int *)(DAT_02961f78 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02961f78 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

