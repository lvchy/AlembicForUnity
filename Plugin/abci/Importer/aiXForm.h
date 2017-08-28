#pragma once

class aiXFormSample : public aiSampleBase
{
typedef aiSampleBase super;
public:
    aiXFormSample(aiXForm *schema);

    void updateConfig(const aiConfig &config, bool &topoChanged, bool &dataChanged) override;

    void getData(aiXFormData &outData) const;

public:
    AbcGeom::XformSample m_sample;
    AbcGeom::XformSample m_nextSample;
private:
    void decomposeXForm(const Imath::M44d &mat, Imath::V3d &scale, Imath::V3d &shear, Imath::Quatd &rotation, Imath::V3d &translation) const;
};


struct aiXFormTraits
{
    typedef aiXFormSample SampleT;
    typedef AbcGeom::IXformSchema AbcSchemaT;
};

class aiXForm : public aiTSchema<aiXFormTraits>
{
typedef aiTSchema<aiXFormTraits> super;
public:
    aiXForm(aiObject *obj);

    Sample* newSample();
    Sample* readSample(const abcSampleSelector& ss, bool &topologyChanged) override;
    bool updateInterpolatedValues(const Abc::ISampleSelector& ss, Sample& sample) const override;
};
