/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6940; label: FUN_006d6940
 */

uint FUN_006d6940(uint *param_1)

{
  byte bVar1;
  
  if (DAT_029755a3 != DAT_029755a2) {
    bVar1 = (&DAT_029755f8)[DAT_029755a2];
    if (param_1 != (uint *)0x0) {
      *param_1 = (uint)(byte)(&DAT_029756f8)[DAT_029755a2];
    }
    DAT_029755a2 = DAT_029755a2 + 1;
    return (uint)bVar1;
  }
  return 0xffffffff;
}

