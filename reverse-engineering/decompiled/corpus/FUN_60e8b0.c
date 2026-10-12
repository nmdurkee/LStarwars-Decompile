/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60e8b0; label: FUN_0060e8b0
 */

void FUN_0060e8b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2140) != 0) {
    *(int *)(in_ECX + 0x2134) = *(int *)(in_ECX + 0x2134) + 1;
    FUN_00617a10();
    (**(code **)(**(int **)(in_ECX + 0x110f0) + 8))();
    FUN_006172d0();
    FUN_00616ce0();
    FUN_00611630();
    FUN_0060e4f0();
    return;
  }
  return;
}

