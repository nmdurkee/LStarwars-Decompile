/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57cd30; label: FUN_0057cd30
 */

int FUN_0057cd30(int param_1,int param_2,int param_3)

{
  if (param_1 == 0) {
    if (param_2 == 0) {
      return 0;
    }
    if (param_3 == 0) {
      return 0;
    }
    param_1 = FUN_0057c970(param_2,param_3);
    if (param_1 == 0) {
      return 0;
    }
  }
  if (7 < DAT_00951c7c) {
    return 0;
  }
  (&DAT_00951c0c)[DAT_00951c7c] = param_1;
  DAT_00951c7c = DAT_00951c7c + 1;
  return param_1;
}

