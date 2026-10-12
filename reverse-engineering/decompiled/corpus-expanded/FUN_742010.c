/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742010; label: FUN_00742010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00742010(int param_1,int param_2,int param_3)

{
  short *in_ECX;
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_800 [2048];
  
  if (0 < param_2) {
    puVar2 = local_800;
    param_3 = param_3 - (int)puVar2;
    iVar1 = param_2;
    do {
      FUN_005b59a0(puVar2,puVar2 + param_3);
      puVar2 = puVar2 + 0x40;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  iVar1 = (int)(char)in_ECX[2] + param_1 * -4;
  if (param_2 * 4 < iVar1) {
    iVar1 = param_2 * 4;
  }
  if ((*(uint *)(in_ECX + 2) & 0xf0000000) != 0x10000000) {
    FUN_006e52e0((int)*in_ECX + param_1 * 4,local_800,iVar1);
    return;
  }
  FUN_006e5750((int)*in_ECX + param_1 * 4);
  return;
}

