/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x5039c0; label: FUN_005039c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005039c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7,int param_8)

{
  int extraout_EDX;
  
  DAT_00921310 = param_3;
  DAT_00921308 = param_1 + 3U & 0xfffffffc;
  DAT_00921334 = param_4;
  DAT_0092132c = param_5;
  DAT_00921330 = param_2;
  DAT_00921338 = param_6;
  DAT_00921300 = param_7;
  DAT_00921344 = param_8;
  DAT_009213d4 = 0;
  DAT_00921340 = DAT_00921308;
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_004fff00();
    param_6 = extraout_EDX;
  }
  if (((param_6 != 0) && (param_7 != 0)) && (param_8 != 0)) {
    return;
  }
  FUN_004fff00();
  return;
}

