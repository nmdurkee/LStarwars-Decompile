/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c820; label: FUN_0060c820
 */

int * FUN_0060c820(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 8);
  uVar2 = *(uint *)(in_ECX + 4);
  *param_1 = 0;
  if (uVar1 < uVar2) {
    FUN_006e9fe6();
  }
  *param_1 = in_ECX;
  param_1[1] = uVar1;
  return param_1;
}

