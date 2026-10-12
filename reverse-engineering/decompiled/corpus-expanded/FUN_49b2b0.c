/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49b2b0; label: FUN_0049b2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049b2b0(int param_1)

{
  uint uVar1;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (((unaff_ESI == DAT_0093d7f0) || (unaff_ESI == DAT_0093d7f4)) &&
     (0.25 < ABS(*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x3c)))) {
    return;
  }
  uVar1 = FUN_00550040(*(undefined2 *)(unaff_ESI + 0x27a));
  if ((0x71c6 < (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f))) &&
     (*unaff_EDI = 1, *(char *)(unaff_ESI + 0x7b5) == '6')) {
    if (param_1 == 0) {
      *unaff_EDI = 0;
    }
    *(uint *)(unaff_ESI + 0xe24) = *(uint *)(unaff_ESI + 0xe24) | 4;
  }
  return;
}

