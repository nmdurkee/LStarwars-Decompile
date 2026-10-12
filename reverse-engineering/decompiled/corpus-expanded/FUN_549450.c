/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549450; label: FUN_00549450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

