/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x549450; label: FUN_00549450
 */

void FUN_00549450(void)

{
  if (DAT_009250c8 == 0) {
    DAT_00925038 = 0;
    DAT_00925039 = 0xff;
    DAT_0092503a = 0xff;
    DAT_0092503b = 0xff;
    DAT_0092503c = 0xff;
    return;
  }
  if ('\0' < DAT_00925038) {
    DAT_0092503a = DAT_0092503a - 1 & 1;
    DAT_0092503b = DAT_0092503b + '\x01';
    DAT_00925039 = 1;
    if (DAT_0092503b == '\x03') {
      DAT_0092503b = '\0';
    }
    DAT_0092503c = DAT_0092503c + 1 & 3;
    return;
  }
  DAT_00925038 = DAT_00925038 + '\x01';
  return;
}

