/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53dd50; label: FUN_0053dd50
 */

undefined4
FUN_0053dd50(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  if (0.0 <= (param_2 - param_4) * (param_3 - param_5) + (param_1 - param_3) * (param_6 - param_4))
  {
    return 1;
  }
  return 0;
}

