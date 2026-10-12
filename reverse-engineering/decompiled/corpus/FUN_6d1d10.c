/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d1d10; label: FUN_006d1d10
 */

void FUN_006d1d10(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  float local_8;
  float local_4;
  
  FUN_0061f7e0(&local_4,&local_8);
  local_4 = local_4 * 640.0;
  local_8 = local_8 * 448.0;
  DAT_02973a18 = param_1;
  uVar1 = FUN_006e6b90(300,0xfa,DAT_02973a78,FUN_006bc860,"Select LED File");
  uVar1 = FUN_006e6b90(uVar1);
  iVar2 = FUN_00619250(uVar1);
  if (iVar2 != 0) {
    uVar3 = 0;
    if (0 < DAT_02973e98) {
      puVar4 = &DAT_02973e9c;
      do {
        if (((uVar3 < 10) && (puVar4 != (undefined *)0x0)) && ((puVar4[0xa4] & 2) != 0)) {
          uVar1 = FUN_00627a80(uVar3,&DAT_0081f9a0,0,0,&LAB_006cf850,puVar4);
          FUN_00618e10(iVar2,uVar1);
        }
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 0xa8;
      } while ((int)uVar3 < DAT_02973e98);
    }
    FUN_006242b0(iVar2,5);
    FUN_00627930(iVar2,1);
    DAT_02973a84 = iVar2;
  }
  return;
}

