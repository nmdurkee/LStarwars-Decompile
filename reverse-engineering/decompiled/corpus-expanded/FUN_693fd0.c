/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x693fd0; label: FUN_00693fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00693fd0(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  
  iVar1 = 2;
  piVar2 = (int *)(in_ECX + 0x130);
  do {
    if ((piVar2[6] != 0) && (piVar2[6] != 1)) {
      FUN_00698400(*piVar2 * 2);
      if (piVar2[6] != 1) {
        piVar2[0xb] = 0;
        piVar2[6] = 1;
      }
      piVar2[5] = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      piVar2[10] = 0;
      piVar2[7] = 0;
    }
    piVar2 = piVar2 + 0xd;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 1;
}

