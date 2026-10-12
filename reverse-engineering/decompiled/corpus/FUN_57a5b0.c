/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a5b0; label: FUN_0057a5b0
 */

void FUN_0057a5b0(int param_1)

{
  DAT_00950770 = 1;
  if ((DAT_00951b80 == 0) || (((*(byte *)(DAT_00951b80 + 100) & 0xe0) != 0 && (DAT_0093b2a4 != 0))))
  {
    DAT_00951b80 = FUN_00573520(*(undefined4 *)(param_1 + 300),0);
  }
  if (DAT_00951b80 == 0) {
    DAT_00951b80 = DAT_00951b94;
  }
  if (DAT_0093d84c != -1) {
    DAT_0093d850 = 1;
  }
  return;
}

