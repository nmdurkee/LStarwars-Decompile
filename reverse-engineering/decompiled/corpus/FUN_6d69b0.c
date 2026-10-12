/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d69b0; label: FUN_006d69b0
 */

undefined4 FUN_006d69b0(undefined1 param_1,undefined1 param_2)

{
  if ((byte)(DAT_029755a3 + 1) != DAT_029755a2) {
    (&DAT_029755f8)[DAT_029755a3] = param_1;
    (&DAT_029756f8)[DAT_029755a3] = param_2;
    DAT_029755a3 = DAT_029755a3 + 1;
    return 1;
  }
  return 0;
}

