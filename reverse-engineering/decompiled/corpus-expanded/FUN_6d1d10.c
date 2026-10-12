/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d1d10; label: FUN_006d1d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
          uVar1 = FUN_00627a80(uVar3,&DAT_0081f9a0,0,0,FUN_006cf850,puVar4);
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

