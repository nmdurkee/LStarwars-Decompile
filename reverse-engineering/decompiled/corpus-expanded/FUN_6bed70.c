/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bed70; label: FUN_006bed70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bed70(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb0) = *param_1;
  *(undefined4 *)(in_ECX + 0xb4) = param_1[1];
  *(undefined4 *)(in_ECX + 0xb8) = param_1[2];
  *(undefined4 *)(in_ECX + 0xbc) = param_1[3];
  return;
}

