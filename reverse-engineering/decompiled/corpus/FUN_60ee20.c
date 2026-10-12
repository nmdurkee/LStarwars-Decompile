/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60ee20; label: FUN_0060ee20
 */

void FUN_0060ee20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076a9c0;
  in_ECX[4] = &PTR_LAB_0076a98c;
  FUN_00612730();
  FUN_00617930();
  FUN_0060e9e0();
  FUN_00633540();
  *in_ECX = &PTR_LAB_0076a94c;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

