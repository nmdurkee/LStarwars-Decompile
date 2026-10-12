/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ace90; label: FUN_005ace90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ace90(void)

{
  int unaff_ESI;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(byte *)(unaff_ESI + 0x108) & 1) != 0) {
    FUN_005b3800(&local_c);
    FUN_005b3620(&local_c,&local_c,-(uint)*(ushort *)(unaff_ESI + 0x134));
    if ((((*(float *)(unaff_ESI + 0x48) < local_c) || (local_c < -*(float *)(unaff_ESI + 0x48))) ||
        (*(float *)(unaff_ESI + 0x4c) < local_8)) ||
       (((local_8 < 0.0 || (*(float *)(unaff_ESI + 0x50) < local_4)) ||
        (local_4 < -*(float *)(unaff_ESI + 0x50))))) {
      return 0;
    }
  }
  return 1;
}

