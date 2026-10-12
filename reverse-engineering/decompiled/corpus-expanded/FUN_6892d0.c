/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x6892d0; label: FUN_006892d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006892d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_c [12];
  
  iVar1 = FUN_0065c8a0();
  if (iVar1 == 0) {
    FUN_00621140();
    FUN_00687e30();
    if (DAT_02923194 != -1) {
      if (DAT_02961f7c == 0) {
        if (DAT_02924af8 == 0) {
          iVar1 = (-(uint)(DAT_02962010 != -1) & 0x7f7f7f) - 0x7f7f80;
        }
        else {
          iVar1 = -0x10000;
        }
      }
      else {
        iVar1 = -0xff0100;
      }
      FUN_005da860(local_c,DAT_02962114,DAT_02923194);
      puVar2 = (undefined4 *)FUN_005cf9c0(local_c);
      FUN_0065bb50(*puVar2,puVar2[1],puVar2[2],0x3f000000,0x3f000000,0x3f000000,0,0,0,0,0,iVar1,
                   DAT_029211f4);
      if (DAT_02961f7c != 0) {
        FUN_00689060(DAT_02962010);
      }
      if (DAT_02924af8 != 0) {
        FUN_006891e0(DAT_02962010);
      }
    }
    if (DAT_029620d0 != 0) {
      FUN_00626b50(DAT_029620d0);
    }
  }
  return;
}

