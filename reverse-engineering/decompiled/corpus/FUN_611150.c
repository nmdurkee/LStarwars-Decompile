/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x611150; label: FUN_00611150
 */

undefined4 * FUN_00611150(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  uVar2 = FUN_00617a00();
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((param_2 + 2 <= 3000 - puVar1[4]) &&
       (((uint)puVar1[7] <= (uint)puVar1[6] || (uVar2 <= (uint)puVar1[6])))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}

