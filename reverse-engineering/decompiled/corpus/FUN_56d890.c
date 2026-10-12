/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56d890; label: FUN_0056d890
 */

bool FUN_0056d890(int param_1,int param_2)

{
  return (1 << ((byte)param_2 & 0x1f) &
         *(uint *)(param_1 + 0x38 + ((int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5) * 4)) != 0;
}

