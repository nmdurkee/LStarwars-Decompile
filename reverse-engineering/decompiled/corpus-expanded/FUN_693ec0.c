/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x693ec0; label: FUN_00693ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char FUN_00693ec0(byte param_1,undefined4 *param_2)

{
  char cVar1;
  int in_ECX;
  bool bVar2;
  
  bVar2 = (param_1 & 1) == 0;
  if (bVar2) {
    *param_2 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(in_ECX + 0xc);
  }
  cVar1 = !bVar2;
  if ((param_1 & 2) == 0) {
    param_2[1] = 0;
  }
  else {
    param_2[1] = *(undefined4 *)(in_ECX + 0x10);
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 4) == 0) {
    param_2[2] = 0;
  }
  else {
    param_2[2] = *(undefined4 *)(in_ECX + 0x14);
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 8) == 0) {
    param_2[3] = 0;
  }
  else {
    param_2[3] = *(undefined4 *)(in_ECX + 0x18);
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 0x10) == 0) {
    param_2[4] = 0;
  }
  else {
    param_2[4] = *(undefined4 *)(in_ECX + 0x1c);
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 0x20) != 0) {
    param_2[5] = *(undefined4 *)(in_ECX + 0x20);
    return cVar1 + '\x01';
  }
  param_2[5] = 0;
  return cVar1;
}

