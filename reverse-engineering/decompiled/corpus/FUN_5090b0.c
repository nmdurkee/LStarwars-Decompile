/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x5090b0; label: FUN_005090b0
 */

undefined4 FUN_005090b0(int param_1)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x63c) != '\0') && (*(int *)(in_ECX + 0x640 + param_1 * 4) != -1)) {
    return 1;
  }
  return 0;
}

