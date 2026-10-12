/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ee710; label: FUN_005ee710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ee710(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if ((in_EAX != -1) && (in_EAX < *(int *)(in_ECX + 0xf0))) {
    iVar1 = in_EAX * 0x10 + *(int *)(in_ECX + 0xf8);
    FUN_005ebeb0(iVar1,*(undefined4 *)(iVar1 + 0xc),0x400000,0x3f800000);
  }
  return;
}

