/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611150; label: FUN_00611150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

