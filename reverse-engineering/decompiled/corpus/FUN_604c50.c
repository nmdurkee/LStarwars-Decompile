/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x604c50; label: FUN_00604c50
 */

int FUN_00604c50(int param_1,byte param_2)

{
  byte bVar1;
  
  if (((int)(uint)param_2 < *(int *)(param_1 + 0x188)) &&
     (bVar1 = *(byte *)((uint)param_2 + *(int *)(param_1 + 0x18c)), bVar1 != 0xff)) {
    return (uint)bVar1 * 0x50 + *(int *)(param_1 + 0x184);
  }
  return 0;
}

