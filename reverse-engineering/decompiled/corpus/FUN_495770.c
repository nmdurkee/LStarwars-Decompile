/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x495770; label: FUN_00495770
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495770(float *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  iVar2 = FUN_00494bb0();
  if (iVar2 == 0) {
    if (30.0 <= *param_1) {
      DAT_0087b5a0 = 2;
      return;
    }
    if (3.0 < _DAT_0092505c != (_DAT_0092505c == 3.0)) {
      FUN_006d6340(0);
      iVar2 = FUN_006d9120(0,0x1a,local_4,local_8,1);
      if (-1 < iVar2) {
        uVar3 = FUN_006d9510(iVar2,0);
        FUN_004f47f0(0,uVar3);
        FUN_004f4340(uVar3,1);
        FUN_006d6340(0);
        cVar1 = FUN_006d95b0(uVar3,0,0xffffffff);
        if (cVar1 != '\0') {
          FUN_00509830(1,DAT_00924810 != 0,0xffffffff);
          return;
        }
        FUN_00509830(0x16,0,0xffffffff);
      }
    }
  }
  return;
}

