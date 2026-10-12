/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7d00; label: FUN_004a7d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a7d00(void)

{
  int unaff_ESI;
  
  if ((*(char *)(unaff_ESI + 0x7b5) == -1) && (*(char *)(unaff_ESI + 0xe32) == '\0')) {
    if (*(char *)(unaff_ESI + 0x281) == '\0') {
      return;
    }
    if (((*(char *)(unaff_ESI + 0x282) == '\0') &&
        ((0.2 <= *(float *)(unaff_ESI + 0xdac) || ((*(uint *)(unaff_ESI + 0xe24) & 0x400) != 0))))
       && (((*(uint *)(unaff_ESI + 0xe24) & 0x400) != 0 ||
           ((*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) == 0.0 ||
            (((*(byte *)(unaff_ESI + 0x1fc) & 0x80) == 0 &&
             (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x164) != 0)))))))) {
      FUN_005621a0();
    }
  }
  if (*(char *)(unaff_ESI + 0x281) != '\0') {
    *(uint *)(unaff_ESI + 0xe24) = *(uint *)(unaff_ESI + 0xe24) & 0xfffffbff;
  }
  return;
}

