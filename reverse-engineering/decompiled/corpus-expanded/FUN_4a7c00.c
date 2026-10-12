/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7c00; label: FUN_004a7c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a7c00(void)

{
  undefined2 uVar1;
  int unaff_ESI;
  
  *(undefined2 *)(unaff_ESI + 0x42) = 5;
  if (((*(char *)(unaff_ESI + 0x7b5) != '+') &&
      ((((*(char *)(unaff_ESI + 0x281) != '\0' || (0.0 < *(float *)(unaff_ESI + 0xd24))) ||
        (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x14) == 0)) ||
       (((*(float *)(unaff_ESI + 0xdac) < 0.2 && (*(float *)(unaff_ESI + 0xda0) != 2e+06)) &&
        ((*(float *)(unaff_ESI + 0xda0) < 0.25 && (*(float *)(unaff_ESI + 0x6c) < 0.0)))))))) &&
     (((*(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x28) <= 0.0 ||
       (*(char *)(unaff_ESI + 0x281) != '\0')) ||
      (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x14) == 0)))) {
    uVar1 = FUN_00415050();
    *(undefined2 *)(unaff_ESI + 0x42) = uVar1;
    return;
  }
  return;
}

