/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c66c0; label: FUN_006c66c0
 */

undefined1 FUN_006c66c0(int *param_1,int param_2)

{
  uint3 in_ECX;
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = (uint)in_ECX;
  if ((param_1[2] == 2) && (param_2 != 0)) {
    uVar2 = CONCAT13(1,in_ECX);
  }
  puVar1 = &stack0xffffffff;
  (**(code **)(*param_1 + 8))(puVar1,1,1,uVar2);
  return (char)((uint)puVar1 >> 0x18);
}

