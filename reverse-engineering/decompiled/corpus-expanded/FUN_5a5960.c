/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a5960; label: FUN_005a5960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a5960(int param_1,float param_2,float *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar5 = param_1;
  FUN_005d0260((int)param_2 + 0x24,&local_24,&param_2);
  param_2 = param_2 * param_2;
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x46c0)) {
    param_1 = 0;
    do {
      if (iVar7 != param_4) {
        iVar8 = *(int *)(iVar5 + 0x46bc) + param_1;
        uVar2 = *(uint *)(iVar8 + 200);
        if ((((uVar2 & 0x40000) != 0) && ((uVar2 & 0x1000000) != 0)) && ((uVar2 & 0x4000000) == 0))
        {
          iVar1 = iVar8 + 0x24;
          iVar6 = FUN_005cfd60(iVar1);
          if (iVar6 != 0) {
            FUN_005d0130(iVar1,local_c,local_18);
            FUN_005d0260(iVar1,&local_24,&local_28);
            pfVar3 = *(float **)(iVar8 + 0x58);
            local_24 = *pfVar3;
            local_20 = pfVar3[1];
            local_1c = pfVar3[2];
            fVar4 = ((local_24 - *param_3) * (local_24 - *param_3) +
                    (local_1c - param_3[2]) * (local_1c - param_3[2])) - local_28 * local_28;
            if ((fVar4 <= param_2) || (fVar4 <= 0.0)) {
              return 1;
            }
          }
        }
      }
      param_1 = param_1 + 0xd4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(iVar5 + 0x46c0));
  }
  return 0;
}

