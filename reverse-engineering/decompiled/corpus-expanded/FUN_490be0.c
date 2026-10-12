/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490be0; label: FUN_00490be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00490be0(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return PTR_DAT_007faaac;
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      return (char *)0x0;
    }
    return "Down(Baddie)";
  }
  return "Down(Goodie)";
}

