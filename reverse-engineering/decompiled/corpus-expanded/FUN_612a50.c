/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612a50; label: FUN_00612a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00612a50(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if (-1 < iVar1) {
    iVar2 = 0;
    if (*(int *)(in_ECX + 0x2c) < 0) {
      *(int *)(in_ECX + 0x2c) = iVar1 << 10;
      if (iVar1 << 10 == 0) {
        *(undefined4 *)(in_ECX + 0x2c) = 1;
      }
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
    }
    iVar1 = iVar1 * 0x400;
    do {
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
      iVar2 = iVar2 + 1;
      if ((iVar1 + 0x400 <= *(int *)(in_ECX + 0x2c)) &&
         (*(int *)(in_ECX + 0x2c) = iVar1, iVar1 == 0)) {
        *(undefined4 *)(in_ECX + 0x2c) = 1;
      }
      if (*(int *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x2c) * 0x18) == 0) {
        if (0x3ff < iVar2) {
          return 0;
        }
        return *(undefined4 *)(in_ECX + 0x2c);
      }
    } while (iVar2 < 0x400);
  }
  return 0;
}

