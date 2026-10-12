/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x498120; label: FUN_00498120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00498120(void)

{
  int unaff_ESI;
  float local_c [3];
  
  if (((((DAT_00951288 == 0) && ((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0)) &&
       ((*(char *)(unaff_ESI + 0x7b5) != '\0' ||
        (*(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x30) * 0.5 <=
         *(float *)(unaff_ESI + 0x77c))))) &&
      (((((0.0 < *(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) ||
          (*(float *)(unaff_ESI + 0x68) != 0.0)) || (*(float *)(unaff_ESI + 0x70) != 0.0)) &&
        (((*(byte *)(unaff_ESI + 0x281) & 2) == 0 && (*(char *)(unaff_ESI + 0x1078) != '\0')))) &&
       (DAT_029999a0 < *(float *)(unaff_ESI + 0x6b8))))) &&
     ((*(float *)(unaff_ESI + 0x6b8) < DAT_029959a0 &&
      ((*(float *)(unaff_ESI + 0x1e0) / 0.21) * 0.035 <
       *(float *)(unaff_ESI + 0x17c) - *(float *)(unaff_ESI + 0x21c))))) {
    if (*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) <= 0.0) {
      local_c[0] = *(float *)(unaff_ESI + 0x68);
      local_c[1] = 0.0;
      local_c[2] = *(float *)(unaff_ESI + 0x70);
      FUN_005b3b30(local_c,local_c);
    }
    else {
      FUN_005b3620(local_c,&DAT_0080250c,*(undefined2 *)(unaff_ESI + 0x5a));
    }
    if (0.0 < (*(float *)(unaff_ESI + 0x6a8) - *(float *)(unaff_ESI + 0x5c)) * local_c[0] +
              (*(float *)(unaff_ESI + 0x6b0) - *(float *)(unaff_ESI + 100)) * local_c[2]) {
      return 1;
    }
  }
  return 0;
}

