/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63db30; label: FUN_0063db30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063db30(void)

{
  int iVar1;
  int iVar2;
  
  FUN_005d0fb0();
  FUN_005d0fe0(DAT_009738b8,0x3f99999a,0x3f99999a);
  FUN_005d1060(DAT_009738b8,0x80ffffff);
  FUN_005d0e80(DAT_009738b8);
  iVar1 = FUN_006e6b90();
  FUN_005db880(0x80,0x200 - iVar1,0x12c0,0x5a0,0x20000080,DAT_029135f4);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d0fe0(DAT_009738b8,0x3f99999a,0x3f99999a);
  FUN_005f35e0(DAT_009738b8,0x280,0x200,0x10,"Burnout Editor");
  iVar2 = iVar1 + 0x200;
  if (DAT_0291396c != 0) {
    FUN_005f35e0(DAT_009738b8,0x280,iVar2,0x10,"Used: %d / %d",*(undefined4 *)(DAT_0291396c + 0x550)
                 ,0x20);
    FUN_005f35e0(DAT_009738b8,0x280,iVar2 + iVar1,0x10,"Default Radius: %0.2f",
                 (double)*(float *)(DAT_0291396c + 0x558));
    iVar2 = iVar2 + iVar1 + iVar1;
    FUN_005f35e0(DAT_009738b8,0x280,iVar2,0x10,"Default Falloff: %0.2f",
                 (double)*(float *)(DAT_0291396c + 0x55c));
    FUN_005f35e0(DAT_009738b8,0x280,iVar2 + iVar1 * 2,0x10,"Current Global Scale/Intensity: %0.2f",
                 (double)*(float *)(DAT_0291396c + 0x68));
    return;
  }
  FUN_005f35e0(DAT_009738b8,0x280,iVar2,0x10,"NO BURNSET LOADED");
  return;
}

