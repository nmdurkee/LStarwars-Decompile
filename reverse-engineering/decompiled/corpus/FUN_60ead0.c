/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60ead0; label: FUN_0060ead0
 */

void FUN_0060ead0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2140) != 0) {
    FUN_00613dd0();
    FUN_00617950();
    (**(code **)(**(int **)(in_ECX + 0x110f0) + 0x10))();
    *(undefined4 *)(in_ECX + 0x2140) = 0;
  }
  return;
}

