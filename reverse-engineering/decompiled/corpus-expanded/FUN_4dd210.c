/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd210; label: FUN_004dd210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd210(int param_1)

{
  DAT_00882a90 = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"throw_object1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"throw_object2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"throw_object3",1);
  return;
}

