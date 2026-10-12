/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c2350; label: FUN_006c2350
 */

void FUN_006c2350(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = (undefined4 *)*in_ECX;
  while (puVar1 != (undefined4 *)0x0) {
    if (puVar1[1] == 0) {
      in_ECX[1] = puVar1[2];
    }
    else {
      *(undefined4 *)(puVar1[1] + 8) = puVar1[2];
    }
    if (puVar1[2] == 0) {
      *in_ECX = puVar1[1];
    }
    else {
      *(undefined4 *)(puVar1[2] + 4) = puVar1[1];
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    in_ECX[2] = in_ECX[2] + -1;
    (**(code **)*puVar1)(1);
    puVar1 = (undefined4 *)*in_ECX;
  }
  return;
}

