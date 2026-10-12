/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x557a50; label: FUN_00557a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00557a50(void)

{
  int unaff_ESI;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(char *)(unaff_ESI + 0x91) == '\x05') || (*(char *)(unaff_ESI + 0x91) == '\x06')) {
    FUN_005b3800(&local_c);
    FUN_005b3620(&local_c,&local_c,-(uint)*(ushort *)(unaff_ESI + 0x84));
    if (((*(float *)(unaff_ESI + 0x5c) < local_c) ||
        (((local_c < -*(float *)(unaff_ESI + 0x5c) || (*(float *)(unaff_ESI + 0x60) < local_8)) ||
         (local_8 < 0.0)))) ||
       ((*(float *)(unaff_ESI + 100) < local_4 || (local_4 < -*(float *)(unaff_ESI + 100))))) {
      return 0;
    }
  }
  return 1;
}

