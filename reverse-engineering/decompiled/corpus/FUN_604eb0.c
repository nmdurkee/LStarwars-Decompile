/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x604eb0; label: FUN_00604eb0
 */

undefined4 FUN_00604eb0(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),in_ECX[1] == param_1[1]);
}

