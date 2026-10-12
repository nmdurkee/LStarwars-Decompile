/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x7059fe; label: UnDecorator::composeDeclaration
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::composeDeclaration(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::composeDeclaration(DName *param_1)

{
  uint uVar1;
  uint uVar2;
  DName *pDVar3;
  DName *pDVar4;
  int iVar5;
  uint uVar6;
  DName *pDVar7;
  DName *pDVar8;
  bool bVar9;
  DName *in_stack_00000008;
  char cVar10;
  char cVar11;
  char cVar12;
  char *pcVar13;
  DName local_70 [8];
  char local_68 [8];
  DName local_60 [8];
  DName local_58 [8];
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  uint local_24;
  DName local_20 [4];
  int local_1c;
  undefined4 local_18;
  uint local_14;
  undefined1 local_10 [4];
  uint local_c;
  uint local_8;
  
  local_28 = 0;
  local_24 = local_24 & 0xfffff000;
  uVar1 = getTypeEncoding();
  local_1c = DName::isUDC(in_stack_00000008);
  if (uVar1 == 0xffff) {
    DName::DName(param_1,1);
    return param_1;
  }
  if (uVar1 == 0xfffe) {
    operator+((DNameStatus)param_1,(DName *)0x2);
    return param_1;
  }
  if (uVar1 == 0xfffd) {
    DName::DName(param_1,in_stack_00000008);
    return param_1;
  }
  local_8 = uVar1 & 0x8000;
  if (local_8 == 0) {
LAB_00705ffe:
    DName::operator+=((DName *)&local_28,in_stack_00000008);
    if (local_8 == 0) {
      if (((uVar1 & 0x7c00) == 0x6800) || ((uVar1 & 0x7c00) == 0x7000)) {
        getVfTableType(param_1);
        return param_1;
      }
      if ((uVar1 & 0x7c00) == 0x6000) {
        getDimension(SUB41(&local_50,0));
        pDVar3 = local_70;
        pDVar4 = param_1;
        pDVar8 = (DName *)DName::operator+((DName *)&local_28,(char)local_68);
        pDVar3 = (DName *)DName::operator+(pDVar8,pDVar3);
        DName::operator+(pDVar3,(char *)pDVar4);
        return param_1;
      }
      if ((uVar1 & 0x7c00) == 0x7c00) {
        getVdispMapType(param_1);
        return param_1;
      }
      uVar2 = uVar1 & 0x6000;
    }
    else {
      uVar2 = (uVar1 & 0x1800) - 0x800;
    }
    if (uVar2 == 0) {
      uVar2 = uVar1 & 0x400;
    }
    else {
      uVar2 = uVar1 & 0x1000;
    }
    if ((uVar2 == 0) || ((uVar1 & 0x1b00) != 0x1000 || local_8 == 0)) {
      if (local_8 == 0) {
        uVar2 = uVar1 & 0x6000;
      }
      else {
        uVar2 = (uVar1 & 0x1800) - 0x800;
      }
      if (uVar2 == 0) {
        uVar2 = uVar1 & 0x400;
      }
      else {
        uVar2 = uVar1 & 0x1000;
      }
      if ((uVar2 != 0) && ((uVar1 & 0x1b00) == 0x1100 && local_8 != 0)) {
        pcVar13 = "`template static data member constructor helper\'";
        goto LAB_007061a7;
      }
      if (local_8 == 0) {
        uVar2 = uVar1 & 0x6000;
      }
      else {
        uVar2 = (uVar1 & 0x1800) - 0x800;
      }
      if (uVar2 == 0) {
        uVar2 = uVar1 & 0x400;
      }
      else {
        uVar2 = uVar1 & 0x1000;
      }
      if ((uVar2 != 0) && ((uVar1 & 0x1b00) == 0x1200 && local_8 != 0)) {
        pcVar13 = "`template static data member destructor helper\'";
        goto LAB_007061a7;
      }
      if (local_8 == 0) {
        if ((uVar1 & 0x7c00) == 0x7800) goto LAB_0070652c;
        goto LAB_007061c6;
      }
LAB_007061cc:
      uVar2 = (uVar1 & 0x1800) - 0x800;
    }
    else {
      pcVar13 = "`local static destructor helper\'";
LAB_007061a7:
      DName::operator+=((DName *)&local_28,pcVar13);
LAB_007061c6:
      if (local_8 != 0) goto LAB_007061cc;
      uVar2 = uVar1 & 0x6000;
    }
    if (uVar2 == 0) {
      uVar2 = uVar1 & 0x400;
    }
    else {
      uVar2 = uVar1 & 0x1000;
    }
    if ((uVar2 == 0) ||
       (((uVar1 & 0x1b00) != 0x1100 || local_8 == 0 && ((uVar1 & 0x1b00) != 0x1200 || local_8 == 0))
       )) {
      pDVar3 = (DName *)getExternalDataType(local_70);
    }
    else {
      pDVar3 = (DName *)operator+((char *)local_70,(DName *)&DAT_007596f8);
    }
LAB_0070624d:
    DName::operator=((DName *)&local_28,pDVar3);
  }
  else {
    local_14 = uVar1 & 0x1800;
    local_c = (uint)(local_14 == 0x800);
    if (local_c == 0) {
      uVar2 = uVar1 & 0x1000;
    }
    else {
      uVar2 = uVar1 & 0x400;
    }
    if ((uVar2 != 0) && ((uVar1 & 0x1b00) == 0x1000)) goto LAB_00705ffe;
    if (local_c == 0) {
      uVar2 = uVar1 & 0x1000;
    }
    else {
      uVar2 = uVar1 & 0x400;
    }
    if ((uVar2 != 0) && (((uVar1 & 0x1b00) == 0x1100 || ((uVar1 & 0x1b00) == 0x1200))))
    goto LAB_00705ffe;
    if ((uVar1 & 0x4000) != 0) {
      if (((~(DAT_0297cb88 >> 1) & 1) == 0) || ((~(DAT_0297cb88 >> 3) & 1) == 0)) {
        pDVar3 = (DName *)getBasedType();
        DName::operator|=((DName *)&local_28,pDVar3);
      }
      else {
        getBasedType();
        pDVar3 = (DName *)operator+((char)&local_48,(DName *)0x20);
        DName::operator=((DName *)&local_28,pDVar3);
      }
    }
    if (local_c == 0) {
      uVar2 = uVar1 & 0x1000;
    }
    else {
      uVar2 = uVar1 & 0x400;
    }
    if ((uVar2 == 0) || (local_14 != 0x1800)) {
      local_3c = local_3c & 0xfffff000;
      local_34 = local_34 & 0xfffff000;
      local_14 = local_14 & 0xfffff000;
      local_44 = local_44 & 0xfffff000;
      local_2c = local_2c & 0xfffff000;
      local_40 = 0;
      local_38 = 0;
      local_18 = 0;
      local_48 = 0;
      local_30 = 0;
      if (local_c == 0) {
        uVar2 = uVar1 & 0x1000;
      }
      else {
        uVar2 = uVar1 & 0x400;
      }
      if (uVar2 != 0) {
        if (local_c != 0) {
          if ((uVar1 & 0x700) == 0x600) {
            getDimension(SUB41(&local_50,0));
            DName::operator=((DName *)&local_40,(DName *)&local_50);
            getDimension(SUB41(&local_50,0));
            DName::operator=((DName *)&local_38,(DName *)&local_50);
          }
          else if ((local_c == 0) || ((uVar1 & 0x700) != 0x500)) goto LAB_00705cfe;
          getDimension(SUB41(&local_50,0));
          DName::operator=((DName *)&local_18,(DName *)&local_50);
        }
LAB_00705cfe:
        getDimension(SUB41(&local_50,0));
        DName::operator=((DName *)&local_48,(DName *)&local_50);
      }
      if ((local_c != 0) && ((uVar1 & 0x700) != 0x200)) {
        if (((byte)DAT_0297cb88 & 0x60) == 0x60) {
          pDVar3 = (DName *)getThisType();
          DName::operator|=((DName *)&local_30,pDVar3);
        }
        else {
          pDVar3 = (DName *)getThisType();
          DName::operator=((DName *)&local_30,pDVar3);
        }
      }
      if (((~(DAT_0297cb88 >> 1) & 1) == 0) || ((~(DAT_0297cb88 >> 4) & 1) == 0)) {
        pDVar3 = (DName *)getCallingConvention();
        DName::operator|=((DName *)&local_28,pDVar3);
      }
      else {
        pDVar3 = (DName *)&local_50;
        pDVar4 = (DName *)getCallingConvention();
        pDVar3 = (DName *)DName::operator+(pDVar4,pDVar3);
        DName::operator=((DName *)&local_28,pDVar3);
      }
      iVar5 = DName::isEmpty(in_stack_00000008);
      if (iVar5 == 0) {
        iVar5 = DName::isEmpty((DName *)&local_28);
        if ((iVar5 == 0) && ((DAT_0297cb88 & 0x1000) == 0)) {
          pDVar3 = (DName *)operator+((char)local_58,(DName *)0x20);
          DName::operator+=((DName *)&local_28,pDVar3);
        }
        else {
          DName::operator=((DName *)&local_28,in_stack_00000008);
        }
      }
      local_4c = local_4c & 0xfffff000;
      pDVar3 = (DName *)0x0;
      local_50 = 0;
      if (local_1c == 0) {
        pDVar3 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,8,0);
        if (pDVar3 == (DName *)0x0) {
          pDVar3 = (DName *)0x0;
        }
        else {
          *(undefined4 *)pDVar3 = 0;
          *(uint *)(pDVar3 + 4) = *(uint *)(pDVar3 + 4) & 0xfffff000;
        }
        pDVar4 = (DName *)getReturnType(local_58);
        DName::operator=((DName *)&local_50,pDVar4);
      }
      else {
        getReturnType(local_58);
        pDVar4 = (DName *)operator+((char *)local_20,(DName *)&DAT_007596f8);
        DName::operator+=((DName *)&local_28,pDVar4);
        if ((DAT_0297cb88 & 0x1000) != 0) goto LAB_0070652c;
      }
      uVar2 = local_c;
      if (local_c == 0) {
        uVar6 = uVar1 & 0x1000;
      }
      else {
        uVar6 = uVar1 & 0x400;
      }
      if (uVar6 != 0) {
        if (local_c == 0) {
LAB_00705f2c:
          DName::operator+=((DName *)&local_28,"`adjustor{");
        }
        else {
          if ((uVar1 & 0x700) == 0x600) {
            cVar12 = (char)local_58;
            pDVar4 = local_20;
            cVar11 = (char)local_10;
            pDVar8 = local_60;
            cVar10 = (char)local_68;
            pDVar7 = (DName *)operator+((char *)local_70,(DName *)"`vtordispex{");
            pDVar7 = (DName *)DName::operator+(pDVar7,cVar10);
            pDVar8 = (DName *)DName::operator+(pDVar7,pDVar8);
            pDVar8 = (DName *)DName::operator+(pDVar8,cVar11);
            pDVar4 = (DName *)DName::operator+(pDVar8,pDVar4);
          }
          else {
            if ((local_c == 0) || ((uVar1 & 0x700) != 0x500)) goto LAB_00705f2c;
            cVar12 = (char)local_70;
            pDVar4 = (DName *)operator+(local_68,(DName *)"`vtordisp{");
          }
          pDVar4 = (DName *)DName::operator+(pDVar4,cVar12);
          DName::operator+=((DName *)&local_28,pDVar4);
        }
        pDVar4 = (DName *)DName::operator+((DName *)&local_48,(char *)local_70);
        DName::operator+=((DName *)&local_28,pDVar4);
      }
      cVar12 = (char)local_70;
      getArgumentTypes();
      pDVar4 = (DName *)operator+((char)local_60,(DName *)0x28);
      pDVar4 = (DName *)DName::operator+(pDVar4,cVar12);
      DName::operator+=((DName *)&local_28,pDVar4);
      if ((uVar2 != 0) && ((uVar1 & 0x700) != 0x200)) {
        DName::operator+=((DName *)&local_28,(DName *)&local_30);
      }
      if ((~(DAT_0297cb88 >> 8) & 1) == 0) {
        pDVar4 = (DName *)getThrowTypes();
        DName::operator|=((DName *)&local_28,pDVar4);
      }
      else {
        pDVar4 = (DName *)getThrowTypes();
        DName::operator+=((DName *)&local_28,pDVar4);
      }
      if (((~(DAT_0297cb88 >> 2) & 1) == 0) || (pDVar3 == (DName *)0x0)) goto LAB_00706256;
      DName::operator=(pDVar3,(DName *)&local_28);
      pDVar3 = (DName *)&local_50;
      goto LAB_0070624d;
    }
    getDimension(SUB41(&local_50,0));
    pDVar3 = (DName *)&local_48;
    pDVar4 = (DName *)DName::operator+(in_stack_00000008,(char)&local_40);
    pDVar3 = (DName *)DName::operator+(pDVar4,pDVar3);
    DName::operator+=((DName *)&local_28,pDVar3);
    getVCallThunkType();
    if ((DAT_0297cb88 & 0x1000) == 0) {
      pcVar13 = (char *)&local_48;
      pDVar3 = (DName *)operator+((char)&local_40,(DName *)0x2c);
      pDVar3 = (DName *)DName::operator+(pDVar3,pcVar13);
      DName::operator+=((DName *)&local_28,pDVar3);
    }
    DName::operator+=((DName *)&local_28,"}\'");
    getCallingConvention();
    if ((((~(DAT_0297cb88 >> 1) & 1) != 0) && ((~(DAT_0297cb88 >> 4) & 1) != 0)) &&
       ((DAT_0297cb88 & 0x1000) == 0)) {
      pDVar3 = (DName *)&local_48;
      cVar12 = (char)&local_40;
      pDVar4 = (DName *)operator+((char)&local_38,(DName *)0x20);
      pDVar4 = (DName *)DName::operator+(pDVar4,cVar12);
      pDVar3 = (DName *)DName::operator+(pDVar4,pDVar3);
      goto LAB_0070624d;
    }
  }
LAB_00706256:
  if (local_8 == 0) {
    uVar2 = uVar1 & 0x6000;
  }
  else {
    uVar2 = (uVar1 & 0x1800) - 0x800;
  }
  if (uVar2 == 0) {
    if ((~(DAT_0297cb88 >> 9) & 1) != 0) {
      if (local_8 == 0) {
        uVar2 = uVar1 & 0x6000;
      }
      else {
        uVar2 = (uVar1 & 0x1800) - 0x800;
      }
      if ((uVar2 == 0) && (local_8 == 0 || (uVar1 & 0x700) == 0x200)) {
        pDVar3 = (DName *)operator+((char *)local_70,(DName *)"static ");
        DName::operator=((DName *)&local_28,pDVar3);
      }
      if (local_8 == 0) {
LAB_00706314:
        uVar2 = uVar1 & 0x6000;
LAB_00706318:
        if (uVar2 == 0) {
          uVar2 = uVar1 & 0x400;
        }
        else {
          uVar2 = uVar1 & 0x1000;
        }
        if (uVar2 == 0) goto LAB_007063c9;
        if (local_8 == 0) {
          uVar2 = uVar1 & 0x6000;
        }
        else {
          uVar2 = (uVar1 & 0x1800) - 0x800;
        }
        if ((uVar2 != 0) || ((uVar1 & 0x700) != 0x500)) {
          if (local_8 == 0) {
            uVar2 = uVar1 & 0x6000;
          }
          else {
            uVar2 = (uVar1 & 0x1800) - 0x800;
          }
          if ((uVar2 != 0) || ((uVar1 & 0x700) != 0x600)) {
            if (local_8 == 0) {
              uVar2 = uVar1 & 0x6000;
            }
            else {
              uVar2 = (uVar1 & 0x1800) - 0x800;
            }
            if ((uVar2 != 0) || ((uVar1 & 0x700) != 0x400)) goto LAB_007063c9;
          }
        }
      }
      else if ((uVar1 & 0x700) != 0x100) {
        if (local_8 == 0) goto LAB_00706314;
        uVar2 = (uVar1 & 0x1800) - 0x800;
        goto LAB_00706318;
      }
      pDVar3 = (DName *)operator+((char *)local_70,(DName *)"virtual ");
      DName::operator=((DName *)&local_28,pDVar3);
    }
LAB_007063c9:
    if ((~(DAT_0297cb88 >> 7) & 1) != 0) {
      if (local_8 == 0) {
        uVar2 = uVar1 & 0x6000;
      }
      else {
        uVar2 = (uVar1 & 0x1800) - 0x800;
      }
      if (uVar2 == 0) {
        if (local_8 == 0) {
          bVar9 = (uVar1 & 0x1800) != 0x800;
        }
        else {
          bVar9 = ((byte)uVar1 & 0xc0) != 0x40;
        }
        if (bVar9) goto LAB_0070641d;
        pcVar13 = "private: ";
LAB_00706498:
        pDVar3 = (DName *)operator+((char *)local_70,(DName *)pcVar13);
        DName::operator=((DName *)&local_28,pDVar3);
      }
      else {
LAB_0070641d:
        if (local_8 == 0) {
          uVar2 = uVar1 & 0x6000;
        }
        else {
          uVar2 = (uVar1 & 0x1800) - 0x800;
        }
        if (uVar2 == 0) {
          if (local_8 == 0) {
            bVar9 = (uVar1 & 0x1800) != 0x1000;
          }
          else {
            bVar9 = ((byte)uVar1 & 0xc0) != 0x80;
          }
          if (!bVar9) {
            pcVar13 = "protected: ";
            goto LAB_00706498;
          }
        }
        if (local_8 == 0) {
          uVar2 = uVar1 & 0x6000;
        }
        else {
          uVar2 = (uVar1 & 0x1800) - 0x800;
        }
        if (uVar2 == 0) {
          if (local_8 == 0) {
            uVar2 = uVar1 & 0x1800;
          }
          else {
            uVar2 = uVar1 & 0xc0;
          }
          if (uVar2 == 0) {
            pcVar13 = "public: ";
            goto LAB_00706498;
          }
        }
      }
    }
  }
  if (local_8 == 0) {
    uVar2 = uVar1 & 0x6000;
  }
  else {
    uVar2 = (uVar1 & 0x1800) - 0x800;
  }
  if (uVar2 == 0) {
    uVar2 = uVar1 & 0x400;
  }
  else {
    uVar2 = uVar1 & 0x1000;
  }
  if ((uVar2 != 0) && ((DAT_0297cb88 & 0x1000) == 0)) {
    pDVar3 = (DName *)operator+((char *)local_70,(DName *)"[thunk]:");
    DName::operator=((DName *)&local_28,pDVar3);
  }
  if ((uVar1 & 0x10000) != 0) {
    pDVar3 = (DName *)operator+((char *)local_70,(DName *)"extern \"C\" ");
    DName::operator=((DName *)&local_28,pDVar3);
  }
LAB_0070652c:
  DName::DName(param_1,(DName *)&local_28);
  return param_1;
}

