/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b5140; label: FUN_006b5140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b5140(int param_1,int param_2)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint in_EDX;
  uint uVar3;
  
  uVar3 = in_EDX & 0x7fff;
  uVar1 = (in_EAX & 0x7fff) - uVar3;
  iVar2 = (int)(((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) * (in_ECX - param_1)) /
          (param_2 - param_1);
  if ((int)uVar1 < 0) {
    return uVar3 - iVar2;
  }
  return iVar2 + uVar3;
}

