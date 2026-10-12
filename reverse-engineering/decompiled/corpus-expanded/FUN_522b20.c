/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522b20; label: FUN_00522b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00522b20(int param_1)

{
  undefined4 *in_EAX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != 0) {
    FUN_00620f10();
    return;
  }
  local_c = *in_EAX;
  local_8 = *(undefined4 *)(DAT_009238e4 + 0x14);
  local_4 = in_EAX[2];
  FUN_00620f10(&local_c);
  return;
}

