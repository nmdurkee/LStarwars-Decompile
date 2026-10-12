/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74af30; label: FUN_0074af30
 */

uint FUN_0074af30(char param_1,char param_2,char param_3)

{
  return -(uint)(param_1 != '\0') & 0x4000 | -(uint)(param_2 != '\0') & 0x2000 |
         -(uint)(param_3 != '\0') & 0x1000 | 0x20;
}

