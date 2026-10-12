/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a770; label: FUN_0057a770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057a770(undefined4 param_1,int param_2,float param_3,float *param_4)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if (((param_2 != 0) && (iVar1 = FUN_0055e340(local_c,0), iVar1 != 0)) &&
     (iVar1 = FUN_00575920(param_1,0xffffffff,(int)*(short *)(param_2 + 0x62),local_c), iVar1 != 0))
  {
    fVar2 = (float10)FUN_005b3c50(local_c,iVar1 + 0xd4,0);
    if (((float)fVar2 < param_3 * param_3) &&
       (DAT_00802c60 = (int)*(short *)(param_2 + 0x62), param_4 != (float *)0x0)) {
      fVar2 = (float10)FUN_005c0240((float)fVar2);
      *param_4 = (float)fVar2;
      return;
    }
  }
  return;
}

